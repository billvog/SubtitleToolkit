/*
	The subtitle text input field syntax highlighter.
*/

#pragma once

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QVector>

class SubtitleTextHighlighter : public QSyntaxHighlighter {
  Q_OBJECT

  public:
    SubtitleTextHighlighter(QTextDocument *parent = 0);

  protected:
    void highlightBlock(const QString &text) override;

  private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> highlightingRules;

    QRegularExpression tagExpression;
    QTextCharFormat tagFormat;
};
