#ifndef VIDEOCLIP_H
#define VIDEOCLIP_H
#include <QObject>
#include <QMediaPlayer>
#include <QVideoSink>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QVideoFrame>
#include <QAudioOutput>

#include <QTimer>

class VideoClip : public QObject{
    Q_OBJECT

public:
    explicit VideoClip(QObject *parent = nullptr);
    ~VideoClip();



    QUrl* getClipSource() const {return clipSource;}
    QVideoSink* getClipSink() const {return clipSink;}
    QMediaPlayer* getClipPlayer() const {return clipPlayer;}
    qint64 getClipDuration() const {return clipPlayer->duration();};



    void setClipWidget(QVideoWidget* v);
    void setClipSink(QVideoWidget* v);
    void setClipSink(QVideoSink* sink);


    void playPlayer();
    void pausePlayer();

private:
    qint64 positionStart;
    qint64 positionEnd;

    QVideoSink* clipSink;
    QMediaPlayer* clipPlayer;
    QAudioOutput* clipAudio;
    QUrl* clipSource;

public slots:

    void frameDoSomething(const QVideoFrame &frame);
    void frameDoSomething2();
};


#endif // VIDEOCLIP_H
