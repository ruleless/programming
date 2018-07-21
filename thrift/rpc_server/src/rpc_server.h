#include <thrift/stdcxx.h>

using namespace apache::thrift;

#ifndef NAMESPACE_BEG
# define NAMESPACE_BEG(ns) namespace ns {
#endif

#ifndef NAMESPACE_END
# define NAMESPACE_END }
#endif

NAMESPACE_BEG(rpc)

struct ProcessorFactory
{
    virtual stdcxx::shared_ptr<TProcessor> newProcessor() = 0;
    virtual const std::string &getName() const = 0;
};

template <class Processor, class Handler>
class ProcessorFactoryImpl : public ProcessorFactory
{
  public:
    ProcessorFactoryImpl(const std::string &name) : mName(name) {}

    virtual stdcxx::shared_ptr<TProcessor> newProcessor()
    {
        return stdcxx::shared_ptr<Processor>(new Processor(stdcxx::make_shared<Handler>()));
    }

    virtual const std::string &getName() const
    {
        return mName;
    }

  private:
    std::string mName;
};

typedef std::vector<ProcessorFactory *> FactoryList;
class ProcessorFactoryRegistry
{
  public:
    ProcessorFactoryRegistry();
    ~ProcessorFactoryRegistry();

    static ProcessorFactoryRegistry *getRegistry();
    static bool isValid();

    void registerFactory(ProcessorFactory *factory);
    void unregisterFactory(ProcessorFactory *factory);

    void all(void (*doit)(ProcessorFactory *f, void *ctx), void *ctx);

  protected:
    FactoryList mFactories;
    static bool mbValid;
};

template <class Processor, class Handler>
class AutoRegisterProcessor
{
  public:
    AutoRegisterProcessor(const std::string &name)
            :mRegistry(ProcessorFactoryRegistry::getRegistry())
            ,mFactory(name)
    {
        mRegistry->registerFactory(&mFactory);
    }

    ~AutoRegisterProcessor()
    {
        if (ProcessorFactoryRegistry::isValid())
        {
            mRegistry->unregisterFactory(&mFactory);
        }
    }

  private:
    ProcessorFactoryRegistry *mRegistry;
    ProcessorFactoryImpl<Processor, Handler> mFactory;
};

NAMESPACE_END // rpc

#define PROCESSOR_REGISTER(Name, Processor, Handler)                    \
    static rpc::AutoRegisterProcessor<Processor, Handler> _autoRegisterRegistry_##Handler(Name)
