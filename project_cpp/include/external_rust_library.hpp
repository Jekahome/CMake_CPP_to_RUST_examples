#include <cstdint>
#include <memory>

extern "C"
{

    std::uint8_t zoo(std::uint8_t i);
    
}

struct myArgs{
    std::uint32_t init;
    std::uint32_t by;  
} init_args{10,5};

 
extern "C"
{
    // Обьявление внешней структуры
    struct Counter;

    // Обьявление реализованных методов из внешней библиотеки
    Counter* createCounter(std::uint32_t);
    Counter* createCounterArgs(myArgs);
    void destroyCounter(Counter*);
    std::uint32_t incrementCounterBy(Counter*, std::uint32_t);
    std::uint32_t getCounterValue(Counter*);
    std::uint32_t decrementCounterBy(Counter*, std::uint32_t);
    std::uint32_t incrementCounterArrayBy(Counter*, const std::uint32_t*, std::uint64_t);
    std::uint32_t decrementCounterArrayBy(Counter*, const std::uint32_t*, std::uint64_t);
    
    class WrapperCounter {
        public:
            WrapperCounter(std::uint32_t init): rustStructCounter(CounterPtr(createCounter(init))) {}

            WrapperCounter(myArgs init = init_args) {
               
               rustStructCounter=CounterPtr(createCounterArgs(init));
            }

            std::uint32_t wrapIncrementCounterBy(std::uint32_t inc) {
               //auto mov = std::move(this->rustStructCounter);
               //Counter* ptr = mov.get();
               //std::uint32_t r = getCounterValue(ptr);
         
                 std::uint32_t r = incrementCounterBy(&*this->rustStructCounter,inc);
                 return r;
            }

            std::uint32_t wrapGetCounterValue(){
               //auto mov = std::move(this->rustStructCounter);
               //Counter* ptr = mov.get();
               //std::uint32_t r = getCounterValue(ptr);

                 std::uint32_t r = getCounterValue(&*this->rustStructCounter);
                 return r;
            }

            std::uint32_t wrapDecrementCounterBy(std::uint32_t dec){
               //auto mov = std::move(this->rustStructCounter);
               //Counter* ptr = mov.get();
               //std::uint32_t r = getCounterValue(ptr);

                 std::uint32_t r = decrementCounterBy(&*this->rustStructCounter,dec);
                 return r;
            }

            std::uint32_t wrapIncrementCounterArrayBy(const std::uint32_t* bys_ptr, std::uint64_t bys_len) {
                 std::uint32_t r = incrementCounterArrayBy(&*this->rustStructCounter,bys_ptr,bys_len);
                 return r;
            }

            std::uint32_t wrapDecrementCounterArrayBy(const std::uint32_t* bys_ptr, std::uint64_t bys_len) {
                 std::uint32_t r = decrementCounterArrayBy(&*this->rustStructCounter,bys_ptr,bys_len);
                 return r;
            }
        private:
            struct DropCounter {
                void operator()(Counter* rs) const {
                    std::cout << "DropCounter"<< std::endl;
                    destroyCounter(rs);
                }
            };
         
            typedef std::unique_ptr<Counter, DropCounter> CounterPtr;
 
            CounterPtr rustStructCounter;
    };
}
