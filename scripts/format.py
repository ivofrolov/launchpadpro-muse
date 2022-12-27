Import('env')

env.AddCustomTarget(
    'format',
    None,
    'astyle --project -r "src/*" "lib/*"',
    title='Format Sources',
    description='Format source files using `astyle`',
)
