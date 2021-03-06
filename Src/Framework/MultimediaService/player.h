#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "multimediautils.h"
#include <QMediaPlayer>
#include <QTimer>
#include <QDebug>

class PlayerPrivate;
class Player : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Player)
public:
    explicit Player(QObject *parent = NULL, int type = MultimediaUtils::MUSIC);
    ~Player();

    void play(int index, QString path);
    void play();
    void pause();
    void setPlayStatus(bool isPlay);
    void seekTo(int progress);
    qint64 getCurrentPosition();
    qint64 getDuration();
    bool isPlaying();
    void setVideoWidget(QVideoWidget *videoWidget);

signals:
    void onPositionChanged(int mediaType, qint64 position, qint64 duration);
    void onPlay(int mediaType, int index, QString &path, qint64 duration);
    void onResume(int mediaType);
    void onPause(int mediaType);
    void onFinish(int mediaType, bool isError);

private slots:
    void onPrepared(bool available);
    void onError(QMediaPlayer::Error error);
    void onCompletion(bool isError);
    void onUpdatePosition(qint64 position);
    void onStatusChanged(QMediaPlayer::State status);
    void onTimeout();

private:
    friend class PlayerPrivate;
    QScopedPointer<PlayerPrivate> m_Private;
};

#endif // PLAYER_H
