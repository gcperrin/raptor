#pragma once

#include <JuceHeader.h>

class WaveShaperComponent: public Component {
public:
    WaveShaperComponent()
    {
    }

    void paint (Graphics& g) override
    {
        // g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
        g.setColour (Colours::black);

        Rectangle<int> container = getLocalBounds();
        Rectangle<int> innerContainer = container.withSizeKeepingCentre(container.getWidth() - 10,
                                                                        container.getHeight() - 10);

        Path path;
        path.addRectangle (innerContainer);
        g.fillPath (path);

    }

    void resized() override
    {


    }

    Colour backgroundColour;

private:

};
