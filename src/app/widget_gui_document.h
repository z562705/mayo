/****************************************************************************
** Copyright (c) 2020, Fougue Ltd. <http://www.fougue.pro>
** All rights reserved.
** See license at https://github.com/fougue/mayo/blob/master/LICENSE.txt
****************************************************************************/

#pragma once

#include <QtWidgets/QWidget>
#include <V3d_TypeOfOrientation.hxx>

namespace Mayo {

class ButtonFlat;
class GuiDocument;
class V3dViewCameraAnimation;
class V3dViewController;
class WidgetClipPlanes;
class WidgetOccView;

class WidgetGuiDocument : public QWidget {
    Q_OBJECT
public:
    WidgetGuiDocument(GuiDocument* guiDoc, QWidget* parent = nullptr);

    GuiDocument* guiDocument() const;
    V3dViewController* controller() const;

    QRect rectControls() const;

    static void paintPanel(QWidget* widget);

private:
    void connectViewProjButton(ButtonFlat* btn, V3d_TypeOfOrientation proj);
    void toggleWidgetClipPlanes();

    GuiDocument* m_guiDoc = nullptr;
    WidgetOccView* m_qtOccView = nullptr;
    V3dViewController* m_controller = nullptr;
    V3dViewCameraAnimation* m_cameraAnimation = nullptr;
    WidgetClipPlanes* m_widgetClipPlanes = nullptr;
    QRect m_rectControls;
};

} // namespace Mayo
