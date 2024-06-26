#include <QCoreApplication>
#include <QtTest>

// add necessary includes here

class testcases : public QObject
{
    Q_OBJECT

public:
    testcases();
    ~testcases();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

testcases::testcases() {}

testcases::~testcases() {}

void testcases::initTestCase() {}

void testcases::cleanupTestCase() {}

void testcases::test_case1() {}

QTEST_MAIN(testcases)

#include "tst_testcases.moc"
