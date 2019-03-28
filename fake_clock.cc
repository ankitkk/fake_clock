#include "fake_clock.hh"

namespace testing {

  wink::signal<wink::slot< void(fake_clock::time_point& time)>> fake_clock::onClockUpdate;

  fake_clock::time_point fake_clock::now_us_;
  const bool fake_clock::is_steady = false;

  void fake_clock::advance(duration d) noexcept {
    now_us_ += d;

    onClockUpdate(now_us_);
  }

  void fake_clock::advanceTo(time_point point) noexcept
  {
      now_us_ = point;
      onClockUpdate(now_us_);
  }

  void fake_clock::reset_to_epoch() noexcept {
    now_us_ -= (now_us_ - time_point());
  }

  fake_clock::time_point fake_clock::now() noexcept {
    return now_us_;
  }     
}
