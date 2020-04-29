#ifndef DATE_TIME_TEST_H
#define DATE_TIME_TEST_H

// 在工程中使用 date_time 库时，需要包含头文件之前定义宏
// BOOST_DATE_TIME_SOURCE 、 BOOST_DATE_TIME_NO_LIB 或者 BOOST_ALL_NO_LIB

#define BOOST_DATE_TIME_SOURCE
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

using namespace std;

#include <boost/assert.hpp>
#include <vector>
#include <algorithm>

// 处理日期，date_time 库的日期基于格里高利历，支持从 1400-01-01 到 9999-12-31 之间的日期计算
void test_date()
{
    date d1;    // 一个无效的日期
    date d2(2020,1,1);
    date d3(2000,Jan, 1);
    date d4(d2);

    cout << d3 - d2 << endl;

    date d8 = d2 + days(10);

    assert(d1 == date(not_a_date_time));
    assert(d2 == d4);
    assert(d3 < d4);

    date d5 = from_string("1999-12-31");
    date d6(from_string("2005/1/1"));
    date d7 = from_undelimited_string("20011118");

    cout << day_clock::local_day() << endl;
    cout << day_clock::universal_day() << endl;
}

// 计算信用卡的最长免息期
// 使用信用卡的当天成为消费日，信用卡每月有一个记账日，在记账日之后有一个固定的免息还款
// 期限，通常为20天
class credit_card
{
public:
    string bank_name;   // 银行名
    int bill_day_no;    // 记账日
    credit_card(const char *bname, int no) :
        bank_name(bname), bill_day_no(no)
    {}
    credit_card(const credit_card &v) :
        bank_name(v.bank_name), bill_day_no(v.bill_day_no)
    {}

    int calc_free_days(date consume_day = day_clock::local_day()) const
    {
        // 得到记账日
        date bill_day(consume_day.year(), consume_day.month(), bill_day_no);
        if (consume_day > bill_day) // 消费日是否已经超过了记账日
        {
            bill_day += months(1);
        }

        return (bill_day - consume_day).days() + 20;    // 计算免息期
    }

    friend bool operator<(const credit_card& l, const credit_card& r)
    {
        // 比较免息期
        return l.calc_free_days() < r.calc_free_days();
    }
};

void test1()
{
    // 判断是否包含中文，QString长度和转换为QByteArray长度比较
//    QString str("aaa");
//    QString str1("啊aa");
//    qDebug() << str.length() << str.toLocal8Bit().length();
//    qDebug() << str1.length() << str1.toLocal8Bit().length();
}

void testSort()
{
    // NOTE std::sort 不能排序list
    std::vector<credit_card> cards;
    cards.push_back(credit_card("A bank", 10));
    cards.push_back(credit_card("B bank", 20));
    cards.push_back(credit_card("C bank", 15));
    cards.push_back(credit_card("D bank", 13));
    cards.push_back(credit_card("E bank", 17));
    std::sort(cards.begin(), cards.end());
    std::vector<credit_card>::iterator iter = cards.begin();
    for (; iter != cards.end(); ++iter)
    {
        cout << iter->bank_name << " : " << iter->calc_free_days() << "  ";
    }
    cout << endl;
}

#endif // DATE_TIME_TEST_H
