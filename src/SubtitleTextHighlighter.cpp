#include "SubtitleTextHighlighter.h"

SubtitleTextHighlighter::SubtitleTextHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    HighlightingRule rule;

    tagFormat.setFontWeight(QFont::Bold);
    tagFormat.setForeground(Qt::darkCyan);
    rule.pattern = QRegularExpression("<b>(.*)</b>|<u>(.*)</u>|<s>(.*)</s>|<i>(.*)</i>", QRegularExpression::InvertedGreedinessOption);
    rule.format = tagFormat;

    highlightingRules.append(rule);
}

void SubtitleTextHighlighter::highlightBlock(const QString &text) {
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);

        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
