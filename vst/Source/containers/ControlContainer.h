#pragma once

#include <JuceHeader.h>
#include "../components/WaveShaperComponent.h"

class ControlContainer: public Component {
public:
    ControlContainer()
    {
        addAndMakeVisible(waveShaperComponent);
    }

    void paint (Graphics& g) override
    {
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
        g.setColour (Colours::darkgrey);

        Rectangle<int> container = getLocalBounds();
        Rectangle<int> innerContainer = container.withSizeKeepingCentre(container.getWidth() - 2,
                                                                        container.getHeight() - 2);

        Path path;
        path.addRectangle (innerContainer);
        g.fillPath (path);
    }

    void resized() override
    {
        Grid grid;
        using Track = Grid::TrackInfo;

        grid.templateRows = { Track (1_fr) };
        grid.templateColumns = { Track (1_fr) };
        grid.items = { GridItem (waveShaperComponent) };
        grid.performLayout (getLocalBounds());
    }

    Colour backgroundColour;

private:

    WaveShaperComponent waveShaperComponent;
};
