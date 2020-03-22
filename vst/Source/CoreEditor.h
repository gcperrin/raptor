#pragma once

#include <JuceHeader.h>
#include "CoreProcessor.h"
#include "containers/BandEQContainer.h"
#include "containers/BandSelectorContainer.h"
#include "containers/ControlContainer.h"

class CoreEditor : public AudioProcessorEditor
{
public:
    CoreEditor (CoreProcessor&);
    ~CoreEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    CoreProcessor& processor;
    BandEQContainer bandEqContainer;
    BandSelectorContainer bandSelectorContainer;
    ControlContainer controlContainer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CoreEditor)
};
