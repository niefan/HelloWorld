#ifndef BMPBUTTON_H
#define BMPBUTTON_H

#include <QAbstractButton>
#include <QScopedPointer>
#include <QSettings>
#include <QSoundEffect>

class BmpButtonPrivate;
class BmpButton : public QAbstractButton
{
    Q_OBJECT
    Q_DISABLE_COPY(BmpButton)
public:
    enum ButtonStatus {
        B_Normal = 0,
        B_Press,
        B_Check,
    };
    enum Type {
        T_Translate = 0,
        T_NoTranslate = 1
    };
    explicit BmpButton(QWidget *parent = NULL);
    ~BmpButton();
    void setNormalBmpPath(const QString &path);
    void setPressBmpPath(const QString &path);
    void setCheckBmpPath(const QString &path);
    void setStatus(const BmpButton::ButtonStatus &status);
    BmpButton::ButtonStatus getStatus();
    void enableLongPress(const bool flag);
    void enableLongPressRestore(const bool flag);
    void setLanguageType(const BmpButton::Type type);
    void setTextColor(Qt::GlobalColor color);
    void setTextColor(const QColor &color);
    void setFontPointSize(const int pointSize);
protected:
    bool event(QEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    virtual void normalPaint(QPainter& painter);
    virtual void pressPaint(QPainter& painter);
    virtual void checkPaint(QPainter& painter);
signals:
    void longPressed();
    void OnPressed();
private slots:
    void onTimeout();
//signals:
//    void bmpButtomPress();
//    void bmpButtonRelease();
private:
    friend class BmpButtonPrivate;
    QScopedPointer<BmpButtonPrivate> m_Private;
    QSettings settings;
    QSoundEffect effect;
};

#endif // BMPBUTTON_H
