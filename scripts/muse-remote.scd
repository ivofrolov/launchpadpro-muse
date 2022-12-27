(
var clock, midiOut, midiDestinations;

MIDIClient.init;
midiDestinations = all {:
	format("% %", endpoint.device, endpoint.name) -> endpoint,
	endpoint <- MIDIClient.destinations
}.asDict(class: Dictionary);

d = midiDestinations.at(midiDestinations.keys.as(Array).at(0));
midiOut = MIDIOut.newByName(d.device, d.name);

clock = TempoClock(60 / 60); // 60 bpm in bps

Window("Muse Remote")
.layout_(
	VLayout(
		PopUpMenu().items_(midiDestinations.keys.as(Array)),
		HLayout(
			VLayout(
				Button()
				.states_([
					["RUN", Color.grey, Color.white],
					["OFF", Color.white, Color.grey],
				])
				.action_({
					arg button;
					if (button.value == 1, {
						clock.play({midiOut.midiClock; 1/24}); // for 24 ppqn
					});
				}),

				Slider()
				.value_(0.5)
				.orientation_(\vertical),
			),

			MultiSliderView()
			.size_(8)
			.value_(1 ! 8)
			.step_(1/40)
			.elasticMode_(1),
		),
	)
)
.onClose_({
	clock.stop;
	MIDIClient.disposeClient;
})
.front;
);
