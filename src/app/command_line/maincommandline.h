#ifndef MAINCOMMANDLINE_H
#define MAINCOMMANDLINE_H

#include "commandline.h"
#include "cli/main_cl_functions/mainclfunctions.h"
#include "cli/main_cl_functions/mainclfunctionscli.h"

class MainCommandLine : public CommandLine
{
    Q_OBJECT

    QString command;
    QList<QString> history;
    int history_index;

public:
    MainCommandLine(QString prompt_id,
                    QMutex *mutex,
                    QWidget *parent = 0);

    ~MainCommandLine();

signals:
    void pushToQueue(Command cmd);
    void runParallel();
    void terminate(QString id);

public slots:
    void emitPushToQueue(Command cmd);
    void emitRunParallel();
    void emitTerminate(QString id);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

    void execute(Function *func);

private:
    void parse(QString text);
    void execute(Command cmd);

    void askForInput();
    void autoInput(QString text);

    void addToHistory(QString cmd);
    void getFromHistory(int index);

    void cancelInput();
};

#endif // MAINCOMMANDLINE_H
