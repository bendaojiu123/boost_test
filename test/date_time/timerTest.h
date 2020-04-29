#ifndef TIMERTEST_H
#define TIMERTEST_H

// test timer.h
// contain timer and date_time
// timer progress_timer progress_display

#include <boost/timer.hpp>

#include <QDebug>

void test1()
{
    boost::timer t;
    qDebug() << "max timespan:" << t.elapsed_max() / 3600 << "h";

    qDebug() << "min timespan:" << t.elapsed_min() << "s";

    qDebug() << "now time elapsed:" << t.elapsed() << "s";
}

#include <boost/progress.hpp>
#include <boost/static_assert.hpp>

template<int N = 2>
class new_progress_timer : public boost::timer
{
public:
    new_progress_timer(std::ostream &os = std::cout)
        : boost::timer(), m_os(os)
    {
        BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
    }
    ~new_progress_timer()
    {
        try {
            // save stream status
            std::istream::fmtflags old_flags = m_os.setf(std::istream::fixed,
                                                         std::istream::floatfield);

            // output time
            m_os << elapsed() << " s \ n" << std::endl;

            // restore istream status
            m_os.flags(old_flags);
            m_os.precision(old_prec);
        } catch (...) {

        }
    }

private:
    std::ostream &m_os;
};

template<>
class new_progress_timer<2>:public boost::progress_timer
{};

#endif // TIMERTEST_H
