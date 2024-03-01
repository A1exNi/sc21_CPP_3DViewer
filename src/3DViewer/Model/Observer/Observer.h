#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_OBSERVER_OBSERVER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_OBSERVER_OBSERVER_H_

#include <list>

namespace s21 {

class Observer {
 public:
  virtual void SendModel() = 0;
  virtual void SendError() = 0;
};

class Observable {
 public:
  void AddObserver(Observer* observer) { observers_.push_back(observer); }
  void SendModel() {
    for (Observer* observer : observers_) {
      observer->SendModel();
    }
  }
  void SendError() {
    for (Observer* observer : observers_) {
      observer->SendError();
    }
  }
  void DeleteObserver(Observer* observer) { observers_.remove(observer); }

 private:
  std::list<Observer*> observers_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_OBSERVER_OBSERVER_H_
