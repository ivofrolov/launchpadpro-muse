import logging


logger = logging.getLogger(__name__)

Import('env')

includes = env.DumpIntegrationIncludes()
paths = ' '.join(includes.get('build', []) + includes.get('compatlib', []))
if not paths:
    logger.warning(
        'Custom `tags` target not added. Could not get include directories.'
    )
    Return()

env.AddCustomTarget(
    'tags',
    None,
    f'find {paths} -name "*.[ch]" | etags -',
    title='Tags',
    description='Generate tag file for Emacs',
)
