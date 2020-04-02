flags = [
        '-Wall',
        '-Wextra',
        '-Werror',
        '-std=c++11',
        '-x',
        'c++',
        '-I/Users/gcperrin/dev/audio/vst_template/vst/JuceLibraryCode/',
        '-I/Users/gcperrin/dev/audio/vst_template/juce/modules/',
        '-I/Users/gcperrin/dev/audio/vst_template/vst/Source/'
        ]

def FlagsForFile(filename):
    return { 'flags': flags, 'do_cache': True }

