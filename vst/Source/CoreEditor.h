#pragma once

#include <JuceHeader.h>
#include "CoreProcessor.h"
#include "containers/BandEQContainer.h"
#include "containers/BandSelectorContainer.h"
#include "containers/ControlContainer.h"

class CoreEditor : public AudioProcessorEditor, public ComponentListener
{
public:
    CoreEditor (CoreProcessor&);
    ~CoreEditor();

    void paint (Graphics&) override;
    void resized() override;

    void componentChildrenChanged(Component& component) override;


private:
    CoreProcessor& processor;
    BandEQContainer bandEqContainer;
    BandSelectorContainer bandSelectorContainer;
    ControlContainer controlContainer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CoreEditor)
};
