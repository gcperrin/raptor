#pragma once

#include <math.h>
#include <JuceHeader.h>
#include "../components/LinLogComponent.h"

class BandEQContainer: public Component {
public:
    BandEQContainer()
    {
        addAndMakeVisible(linLogComponent);
    }

    void paint (Graphics& g) override
    {
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
        g.setColour (Colours::black);

        // Draw base graph background
        Rectangle<int> container = getLocalBounds();
        Rectangle<int> innerContainer = container.withSizeKeepingCentre(container.getWidth() - 2,
                                                                        container.getHeight() - 2);
        Path path;
        path.addRectangle (innerContainer);
        g.fillPath (path);

        // Draw log lines across width
        g.setColour (Colours::lightgrey);
        int width = container.getWidth() / 3;
        for (int i = 1; i < 11; i++)
        {
            float xCord = log10(i);

            Line<float> line (Point<float> (xCord * width, 2),
                              Point<float> (xCord * width, container.getHeight() - 2));
            g.drawLine (line, 1.0f);

            Line<float> line2 (Point<float> ((xCord * width) + width, 2),
                              Point<float> ((xCord * width) + width, container.getHeight() - 2));
            g.drawLine (line2, 1.0f);

            Line<float> line3 (Point<float> ((xCord * width) + (width * 2), 2),
                               Point<float> ((xCord * width) + (width * 2), container.getHeight() - 2));
            g.drawLine (line3, 1.0f);
        }

    }

    void resized() override
    {
        // FlexBox fb;
        // fb.flexWrap = FlexBox::Wrap::wrap;
        // fb.justifyContent = FlexBox::JustifyContent::center;
        // fb.alignContent = FlexBox::AlignContent::center;
        // fb.performLayout (getLocalBounds().toFloat());
    }



    Colour backgroundColour;

private:

    LinLogComponent linLogComponent;
};
