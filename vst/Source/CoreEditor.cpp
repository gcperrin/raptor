#include "CoreProcessor.h"
#include "CoreEditor.h"
#include "CoreStyle.h"


CoreEditor::CoreEditor (CoreProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

    setResizable (true, false);
    setResizeLimits (300, 250, 10000, 10000);
    centreWithSize (getWidth(), getHeight());

    // setSize (800, 600);
    addAndMakeVisible(bandEqContainer);
    addAndMakeVisible(bandSelectorContainer);
    addAndMakeVisible(controlContainer);
    setSize (800, 600);


}

CoreEditor::~CoreEditor() {}

void CoreEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    // g.setColour (Colours::white);

}

void CoreEditor::resized()
{
    Grid grid;
    using Track = Grid::TrackInfo;

    grid.templateRows = { Track (10_fr), Track (1_fr), Track (10_fr) };
    grid.templateColumns = { Track (1_fr) };
    grid.items = { GridItem (bandEqContainer), GridItem (bandSelectorContainer), GridItem (controlContainer) };
    grid.performLayout (getLocalBounds());
}
