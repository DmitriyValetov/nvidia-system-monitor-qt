#ifndef QNVSM_MAINWINDOW_H
#define QNVSM_MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>

#include "core/WorkerThread.h"
#include "core/Worker.h"

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void closeEvent(QCloseEvent *event) override;

private:
    WorkerThread *workerThread;
    QTabWidget *tabs;
    QSplitter *utilizationSplitter;

private:
    QString getSplitterStylesheet();
    void saveSettings();
    void loadSettings();

private slots:
    static void about();
    static void help();
};

#endif
