#pragma once

#include <JuceHeader.h>

class ControlContainer: public Component {
public:
    ControlContainer()
    {
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
        FlexBox fb;
        fb.flexWrap = FlexBox::Wrap::wrap;
        fb.justifyContent = FlexBox::JustifyContent::center;
        fb.alignContent = FlexBox::AlignContent::center;
        fb.performLayout (getLocalBounds().toFloat());
    }

    Colour backgroundColour;

private:

};
