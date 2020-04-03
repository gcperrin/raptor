flags = [
        '-Wall',
        '-Wextra',
        '-Werror',
        '-std=c++14',
        '-x',
        'c++',
        '-I/Users/gcperrin/dev/audio/vst_template/vst/build/JuceLibraryCode',
        '-I/Users/gcperrin/dev/audio/vst_template/vst/JuceLibraryCode',
        '-I/Users/gcperrin/dev/audio/vst_template/juce/modules',
        '-I/Users/gcperrin/dev/audio/vst_template/vst/Source'
        ]


def Settings( **kwargs ):
    return { 'flags': flags, 'do_cache': True }

