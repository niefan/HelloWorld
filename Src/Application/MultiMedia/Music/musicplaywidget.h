#ifndef MUSICPLAYWIDGET_H
#define MUSICPLAYWIDGET_H

#include <QWidget>


class MusicPlayWidgetPrivate;
class MusicPlayWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(MusicPlayWidget)
public:
    explicit MusicPlayWidget(QWidget *parent = 0);
    ~MusicPlayWidget();

    void setPlay(const QString &fileName, const long endTime);

protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:
 void onSwitchPlayMode(int mode);
 void onSwitchStatus(bool isPlay);
private slots:
 void onSwitchIndex(bool isNext);
private:
    Q_DECLARE_PRIVATE(MusicPlayWidget)
    MusicPlayWidgetPrivate* const d_ptr;
};

#endif // MUSICPLAYWIDGET_H
