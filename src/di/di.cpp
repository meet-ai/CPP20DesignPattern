
#include <boost/di.hpp>
#include <spdlog/spdlog.h>
using namespace std;
//namespace di = boost::di;
//using namespace boost;
class IWindow{
  virtual void open(int numbers) = 0;
};


struct Window:IWindow {
  void open(int numbers) {
    spdlog::info("open the window");
  }
};


class IWheel {
public:
  virtual void spin() = 0;
};

class Wheel : public IWheel {
public:
  void spin() override {
  }
};

struct Car {
  unique_ptr<IWindow> window;
  unique_ptr<IWheel> wheel;
};
struct SS {
  
};
struct Name {
  Name(SS ss) {
    spdlog::info("name construct");
  }
  ~Name() {
    spdlog::info("name deconstruct");
  }
};
int main() {
  //1. 创建注入器
  auto injector = boost::di::make_injector(
                                           boost::di::bind<IWheel>.to<Wheel>(),
                                           boost::di::bind<IWindow>.to<Window>()
                                           );
  //                                          boost::di::bind<Car>.to<Car>()
  //2注入器创建新对象
  auto wheel= injector.create<unique_ptr<Wheel>>();
  auto window = injector.create<unique_ptr<Window>>();
  auto car = injector.create<unique_ptr<Car>>();

  auto name = injector.create<unique_ptr<Name>>();
}
