#pragma once

#include <JuceHeader.h>

class BandSelectorContainer: public Component {
public:
    BandSelectorContainer()
    {

        bandOne.setButtonText ("Band 1");
        // openButton.onClick = [this] { openButtonClicked(); };
        bandOne.setEnabled (true);

        bandTwo.setButtonText ("Band 2");
        bandThree.setButtonText("Band 3");

        addAndMakeVisible(bandOne);
        addAndMakeVisible(bandTwo);
        addAndMakeVisible(bandThree);
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
        grid.templateColumns = { Track (1_fr), Track (1_fr), Track (1_fr) };
        grid.items = { GridItem (bandOne), GridItem (bandTwo), GridItem (bandThree) };
        grid.performLayout (getLocalBounds());
    }

    Colour backgroundColour;

private:
    TextButton bandOne;
    TextButton bandTwo;
    TextButton bandThree;
};
