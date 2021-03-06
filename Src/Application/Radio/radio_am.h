#ifndef RADIO_AM_H
#define RADIO_AM_H

#include "Src/Framework/Base/Core/activity.h"
#include <QStackedLayout>
#include <QList>
#include <QPoint>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QRect>
#include <QScopedPointer>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QPixmap>

class RadioAmPrivate;
class RadioAm : public Activity
{
    Q_OBJECT
    Q_DISABLE_COPY(RadioAm)

public:

    RadioAm(QObject *parent = 0);

    void onCreate(QWidget *parent=0);
    void onStart();
    void onResume();
    void onPause();
    void onStop();
    void onDestroy();
    bool onBackPressed();
    void onLanguageChanged();
    void onReceiveBroadcast(AppType appType,OMessage &msg);
    void onReceiveCmd(AppType appType,OMessage &msg);

private:
    Q_DECLARE_PRIVATE(RadioAm)
    RadioAmPrivate* const d_ptr;

};

//----------
class RadioAmPresetFreqDelegate : public CustomItemDelegate
{
    Q_OBJECT
    Q_DISABLE_COPY(RadioAmPresetFreqDelegate)
public:
    explicit RadioAmPresetFreqDelegate(RadioAmPrivate *radioPri,QObject* parent = NULL);
    ~RadioAmPresetFreqDelegate();

protected:

    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
private:
    void mousePressEvent(QMouseEvent* event,
                                 QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index);
    void mouseMoveEvent(QMouseEvent* event,
                                QAbstractItemModel *model,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index);
    void mouseReleaseEvent(QMouseEvent* event,
                                   QAbstractItemModel *model,
                                   const QStyleOptionViewItem &option,
                                   const QModelIndex &index);

    bool editorEvent(QEvent* event,
                     QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

protected slots:
    void onCurrentIndexChange(const QModelIndex &index);
    void onPressIndexChanged(const QModelIndex &index);
private:
    const RadioAmPrivate *mRadioPri;
    QModelIndex m_PressIndex;
    QModelIndex m_CurIndex;
    QPoint m_StartMovePoint;
    QScopedPointer<QPixmap> m_Interval_Line;
    QScopedPointer<QPixmap> m_SaveIconNormal;
    QScopedPointer<QPixmap> m_SaveIconPressed;
    QScopedPointer<QPixmap> m_RemoveIconNormal;
    QScopedPointer<QPixmap> m_RemoveIconPressed;
    const QRect mFunIconRect;
    friend class RadioAmPrivate;

};

//----------
class RadioAmListFreqDelegate : public CustomItemDelegate
{
    Q_OBJECT
    Q_DISABLE_COPY(RadioAmListFreqDelegate)
public:
    explicit RadioAmListFreqDelegate(RadioAmPrivate *radioPri,QObject* parent = NULL);
    ~RadioAmListFreqDelegate();
private:
    void mousePressEvent(QMouseEvent* event,
                                 QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index);
    void mouseMoveEvent(QMouseEvent* event,
                                QAbstractItemModel *model,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index);
    void mouseReleaseEvent(QMouseEvent* event,
                                   QAbstractItemModel *model,
                                   const QStyleOptionViewItem &option,
                                   const QModelIndex &index);

protected:
    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
protected slots:
    void onCurrentIndexChange(const QModelIndex &index);
    void onPressIndexChanged(const QModelIndex &index);
private:
    const RadioAmPrivate *mRadioPri;
    QModelIndex m_PressIndex;
    QModelIndex m_CurIndex;
    QPoint m_StartMovePoint;
    QScopedPointer<QPixmap> m_Interval_Line;
    friend class RadioAmPrivate;
};


//----------
class RadioListView;
class RadioProcess;
class RadioAmPrivate :public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(RadioAmPrivate)
public:
    explicit RadioAmPrivate(RadioAm* parent);
    ~RadioAmPrivate(){delete q_ptr;}
    void initializeBasicWidget(QWidget *parent);
    enum Tab{
        AM =0,
        PRESET,
        LIST,
    };
private:
    Q_DECLARE_PUBLIC(RadioAm)
    RadioAm* const q_ptr;

    friend class RadioAmPresetFreqDelegate;
    friend class RadioAmListFreqDelegate;

    RadioProcess *mProcess;

    //----------
    //----------
    BmpWidget *mTabBar;
    BmpButton *mStateBarTab_AM;
    BmpButton *mStateBarTab_Preset;
    BmpButton *mStateBarTab_List;

    QStackedLayout *mFragmentViewLayout;
    QWidget *mAmFragmentContain;
    QWidget *mAmFragmentView;
    QWidget *mPresetFragmentView;
    QWidget *mListFragmentView;

    BmpWidget *mAmFragment_FreqBg;
    TextWidget *mAmFragment_FreqText;
    Slider    *mAmFreqBarSlider;

    QStackedLayout *mBottomBarLayout;
    QWidget *mBottomBar;
    BmpWidget *mBottom_Am;
    BmpWidget *mBottom_Preset;
    BmpWidget *mBottom_List;

    BmpButton *mBottom_Am_Prev;
    BmpButton *mBottom_Am_Seek_Prev;
    BmpButton *mBottom_Am_Seek_Next;
    BmpButton *mBottom_Am_Next;

    BmpButton *mBottom_Preset_Seek_Prev;
    BmpButton *mBottom_Preset_AutoSearch;
    BmpButton *mBottom_Preset_Seek_Next;

    BmpButton *mBottom_List_Seek_Prev;
    BmpButton *mBottom_List_Search;
    BmpButton *mBottom_List_Seek_Next;

    //CustomListView *mRadioPresetFragmentListView;
    RadioListView *mRadioPresetFragmentListView;
    CustomScrollBar *mRadioPresetFragmentListViewScrollBar;
    RadioAmPresetFreqDelegate *mRadioPresetDelegate;
    QStandardItemModel *mRadioPresetStandardItemModel;

    //CustomListView *mRadioListFragmentListView;
    RadioListView *mRadioListFragmentListView;
    CustomScrollBar *mRadioListFragmentListViewScrollBar;
    RadioAmListFreqDelegate *mRadioListDelegate;
    QStandardItemModel *mRadioListStandardItemModel;

    Tab mTab;

    void tabSwitch(const Tab mytab);
    void initRadioAmFragment();
    void initRadioPresetFragment();
    void initRadioPresetData();
    void initRadioListFragment();
    void initRadioListData();
    void onStart();

public slots:
    //----------
    void doReFreshCurFreq(const int &curFreq,bool updatePreset=false,bool updateList=false);
    void doReFreshPresetFreqs(const QList<int> &presetFreqs);
    void doReFreshListFreqs(const QList<int> &listFreqs);
    //----------
private slots:
    void onBtnTabAm();
    void onBtnTabPreset();
    void onBtnTabList();

    void onBtnBottomAmPrev();
    void onBtnBottomAmSeekPrev();
    void onBtnBottomAmSeekNext();
    void onBtnBottomAmNext();
    void onBtnBottomAmSeekPrevLong();
    void onBtnBottomAmSeekNextLong();

    void onBtnBottomPresetSeekPrev();
    void onBtnBottomPresetAutoSearch();
    void onBtnBottomPresetSeekNext();

    void onBtnBottomListSeekPrev();
    void onBtnBottomListSearch();
    void onBtnBottomListSeekNext();

    void doSliderPressed(const int value);
    void doSliderMoved(const int value);
    void doSliderReleased(const int value);

};

#endif // RADIO_AM_H
