#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "database/realtimedatabase.h"
#include "database/staticdatabase.h"
#include "core/analysis.h"
#include "sampletreewidget.h"
#include "matchlist.h"
#include "exonnavigator.h"
#include "basealigntable.h"
#include "dialog/openfiledlg.h"
#include "dialog/allelepairdlg.h"
#include "dialog/alignmentdialog.h"
#include <QtGui>
#include <QtCore>
#include "Main_Oscillogram.h"
#define VERSION "1.0.5.1"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

    void setDatabaseInfo(bool has);
    void onWindowOpen();
public slots:
    void slotOpen();
    void slotSave();
    void slotDelete();
    void slotLoadFile();
    void slotReport();
    void slotFileChanged(SignalInfo &signalInfo, int type);
    void slotAlignPair();
    void slotAlignLab();
    void slotMarkAllSampleApproved();
    void slotMarkAllSampleReviewed();
    void slotReset();
    void slotControl();
    void slotSetExonTrim();
    void slotUpdateDatabase();
    void slotchengebp()
    {
        if(analyseLater->isIconVisibleInMenu())
            analyse->setEnabled(true);
    }
    void slotanalyse()
    {
        analyse->setEnabled(false);
    }

    void slotApplyOne();
    void slotApplyAll();
    void slotAnalyseLater()
    {
        analyseLater->setIconVisibleInMenu(true);
        analyseNow->setIconVisibleInMenu(false);
    }
    void slotAnalyseNow()
    {
        analyseLater->setIconVisibleInMenu(false);
        analyseNow->setIconVisibleInMenu(true);
    }

    void slotDocument();
    void slotAbout();
    void slotMsgStr(QString msgstr); //新增
signals:
    void signalFileChanged(SignalInfo &signalInfo, int type);
    void signalAllelePair(QString &allele1, QString &allele2);
protected:
    void closeEvent(QCloseEvent *e);
    void timerEvent(QTimerEvent *e); //新增
private:
    void createActions();
    void createMenus();
    void createBars();
    void createDefault();
    void setDeleteFile(int dateNum);//新增，设置需要删除的天数，并找到需要删除的文件夹。
    bool removeFolderContent(QString &folderDir);//新增，删除文件夹下所有内容和文件
private:
    //    QWidget *centralWidget;
    //    QVBoxLayout *vBoxLayout;
    bool has_database;
    SampleTreeWidget *sampleTree;
    MatchListWidget *matchListTable;
    ExonNavigator *exonNavigator;
    BaseAlignTable *baseAlignTable;
    Main_Oscillogram * main_mscillogram;
    QMenu *menuadd;
    //    RegionShow *regionShow;
    //    QSplitter *rightSplitter;
    //    QSplitter *leftSplitter;
    //    QSplitter *mainSplitter;

    QMenu *menuFile;
    QMenu *menuTool;
    QMenu *menuFileTree;
    QMenu *menuTypeTable;
    QMenu *menuRegionShow;
    AlignmentDialog  *align;

    QMenuBar *menuBar;
    QToolBar *toolBarFile;
    QToolBar *toolBarTool;
    QToolBar *toolBarPeak;
    QStatusBar *statusBar;

    QAction *actionOpenNewFile;
    QAction *actionOpenOldFile;
    QAction *actionSaveAll;
    QAction *actionDeleteAll;
    QAction *actionReport;

    QAction *actionReset;

    QAction *actionMarkSuccessfulAll;
    QAction *actionMarkFinishedAll;
    QAction *actionAllelePairAlign;
    QAction *actionLabAlleleAlign;

    QAction *actionBackward;
    QAction *actionForward;
    QAction *actionShowGSSPZCode;
    QAction *actionShowUndefinedExon;


    QAction *actionZoomYAxisIncrease;
    QAction *actionZoomYAxisReduce;
    QAction *actionZoomYIncrease;
    QAction *actionZoomYReduce;
    QAction *actionZoomXIncrease;
    QAction *actionZoomXReduce;
    QAction *actionZoomReset;

    QAction *actionApplyOne;
    QAction *actionApplyAll;
    QAction *analyseLater;
    QAction *analyseNow;
    QAction *analyse;

    QMenu *menuSet;

    QAction *actionControl;

    QAction *actionExonTrim;
    QAction *actionUpdateDatabase;

    QMenu *menuHelp;
    QAction *actionAbout;
    QAction *actionDocument;

    SignalInfo signalInfo_;

    int    timerID; //新增
    QLineEdit *msgLabel; //新增
    int     space; //新增
};


#endif // MAINWINDOW_H
