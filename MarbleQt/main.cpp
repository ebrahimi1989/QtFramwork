#include <QApplication>
#include <marble/MarbleDirs.h>
#include <marble/MarbleWidget.h>
#include <marble/MarbleModel.h>

#include <marble/GeoDataDocument.h>
#include <marble/GeoDataCoordinates.h>
#include <marble/GeoDataPlacemark.h>
#include <marble/GeoDataLineString.h>
#include <marble/GeoDataLinearRing.h>
#include <marble/GeoDataTreeModel.h>
#include <marble/GeoDataStyle.h>
#include <marble/GeoDataIconStyle.h>
#include <marble/GeoDataLineStyle.h>
#include <marble/GeoDataPolyStyle.h>
#include <marble/MarbleWidget.h>
#include <marble/MarbleModel.h>
#include <marble/RouteRequest.h>
#include <marble/RoutingManager.h>
#include <marble/GeoPainter.h>
#include <cstdio>

using namespace Marble;

class MyMarbleWidget : public MarbleWidget
{
public:
    virtual void customPaint(GeoPainter* painter);
};

void MyMarbleWidget::customPaint(GeoPainter* painter)
{
    GeoDataCoordinates home(8.4, 49.0, 0.0, GeoDataCoordinates::Degree);
    painter->setPen(Qt::green);
    painter->drawEllipse(home, 7, 7);
    painter->setPen(Qt::black);
    painter->drawText(home, "Hello Marble!");
}

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    Marble::MarbleWidget *mapWidget = new Marble::MarbleWidget;
    mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
    mapWidget->show();
    return app.exec();
}
