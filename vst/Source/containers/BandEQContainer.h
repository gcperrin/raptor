#pragma once

#include <string.h>
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
        int height = container.getHeight();
        float width = container.getWidth();
        Rectangle<int> innerContainer = container.withSizeKeepingCentre(width - 2,
                                                                        height - 2);
        Path path;
        path.addRectangle (innerContainer);
        g.fillPath (path);

        // Draw log lines across width
        g.setColour (Colours::dimgrey);
        width = width / 3.4;
        g.setFont (10.0f);
        float lsize = 1.0f;

        for (int i = 1; i < 11; i++)
        {
            float xCord = log10(i) * width;

            // draw text
            if (i % 2 == 0) {
              g.setColour(Colours::grey);
              g.drawText (std::to_string(i) + "0",
                            xCord,
                            height - 15,
                            25,
                            15,
                            Justification::left,
                            true);

              g.drawText (std::to_string (i) + "00",
                          xCord + width,
                          height - 15,
                          25,
                          15,
                          Justification::left,
                          true);

              g.drawText (std::to_string(i) + "K",
                          xCord + (width * 2),
                          height - 15,
                          25,
                          15,
                          Justification::left,
                          true);
              g.setColour (Colours::dimgrey);
            }

            if (i % 10 == 0) { lsize = 2.0f; }

            // draw lines
            Line<float> line (Point<float> (xCord, 2),
                              Point<float> (xCord, height - 15));

            Line<float> line2 (Point<float> (xCord + width, 2),
                               Point<float> (xCord + width, height - 15));

            Line<float> line3 (Point<float> (xCord + (width * 2), 2),
                               Point<float> (xCord + (width * 2), height - 15));

            g.drawLine (line, lsize);
            g.drawLine (line2, lsize);
            g.drawLine (line3, lsize);
            lsize = 1.0f;

        }

        // last marking line
        float xCord = log10(2) * width;
        Line<float> line (Point<float> (xCord + (width * 3), 2),
            Point<float> (xCord + (width * 3), height - 15));
        g.drawLine (line, 1.0f);
        g.drawText ("20K",
                    xCord + (width * 3),
                    height - 15,
                    20,
                    15,
                    Justification::left,
                    true);

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
