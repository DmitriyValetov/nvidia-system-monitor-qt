#include "NVSMIParser.h"
#include "Utils.h"

using namespace std;
using namespace Utils;

// nvidia-smi process output indices
namespace NVSMIProcess {
enum {
    GPUIdx = 1,
    PID,
    Type,
    Sm,
    Mem,
    Enc,
    Dec,
    FbMem,
    Name
};

constexpr char Command[] = "nvidia-smi pmon -c 1 -s um";
}

QRegularExpression NVSMIParser::processListRegex;

inline QString repeatString(const QString &str, int times) {
    QString result;

    for (int i = 0; i < times; i++)
        result += str;

    return result;
}

/* Process list example:

# gpu        pid  type    sm   mem   enc   dec    fb   command
# Idx          #   C/G     %     %     %     %    MB   name
    0       4673     G     -     -     -     -     0   java
    0       4765     G     0     0     -     -     4   Xorg

 * Parse pattern:
 *  n           n  C/G   n/-   n/-   n/-   n/-   n/-   process name
 */

#define spacer R"([ \t]*)"

void NVSMIParser::init() {
    QString processListPattern =
            repeatString(spacer "([0-9]+)", 2) + // gpu id, pid
            spacer +
            "([CG])" + // type
            repeatString(spacer R"(([0-9\-]+))", 5) + // sm, mem, enc, dec, fb mem
            spacer +
            R"(([^ \t\n]+))"; // process name

    processListRegex.setPattern(processListPattern);
}

vector<ProcessInfo> NVSMIParser::getProcesses() {
    vector<ProcessInfo> info;

    QRegularExpressionMatchIterator i = processListRegex.globalMatch(exec(NVSMIProcess::Command).c_str());

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();

        info.emplace_back(
                match.captured(NVSMIProcess::Name), match.captured(NVSMIProcess::Type),
                match.captured(NVSMIProcess::GPUIdx), match.captured(NVSMIProcess::PID),
                match.captured(NVSMIProcess::Sm), match.captured(NVSMIProcess::Mem),
                match.captured(NVSMIProcess::Enc), match.captured(NVSMIProcess::Dec),
                match.captured(NVSMIProcess::FbMem)
        );
    }

    return info;
}