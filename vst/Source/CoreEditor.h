
#pragma once

#include <JuceHeader.h>
#include "CoreProcessor.h"

class CoreEditor  : public AudioProcessorEditor,
                    private Slider::Listener
{
public:
    CoreEditor (CoreProcessor&);
    ~CoreEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (Slider* slider) override;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CoreProcessor& processor;

    Slider slider;
    std::unique_ptr<ToggleButton> toggleButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CoreEditor)
};
