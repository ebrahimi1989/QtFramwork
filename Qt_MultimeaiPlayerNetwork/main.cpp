#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QMediaPlayer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMediaPlayer *player = new QMediaPlayer;
    QMediaContent *mc=new QMediaContent(QUrl("http://70.200.35.190:8000/home/Videos/1.mp4"));
    player->setMedia(*mc);
    player->setVolume(50);
    QVideoWidget *videoWidget = new QVideoWidget;
    videoWidget->resize(700,700);
    videoWidget->show();
    player->setVideoOutput(videoWidget);
    player->play();

    qDebug()<<player->availableMetaData()<<player->currentMedia().canonicalUrl();
    qDebug()<<player->errorString();

    return a.exec();
}
