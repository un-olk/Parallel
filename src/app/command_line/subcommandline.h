#ifndef SUBCOMMANDLINE_H
#define SUBCOMMANDLINE_H

#include <QDebug>

#include "commandline.h"
#include "task.h"

class SubCommandLine : public CommandLine
{
    Q_OBJECT

    uint _index;

public:
    SubCommandLine(uint index, QWidget *parent = 0);
    ~SubCommandLine();

    bool isFree() const;

    void execute(Task task);

signals:
    void wasReleased(uint index);
};

#endif // SUBCOMMANDLINE_H
