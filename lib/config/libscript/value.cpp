
#include <cstring>

namespace script
{

ValueImpl::ValueImpl(Type t, Engine *e) : ref(0), type(t), engine(e)
{
  const int size = sizeof(BuiltIn);
  std::memset(data.memory, 0, size);
}

ValueImpl::BuiltIn::BuiltIn()
  : qobject(nullptr)
  , valueptr(nullptr)
{

}

ValueImpl::Data::Data()
{
  ptr = 0;
}

ValueImpl::Data::~Data()
{
  ptr = 0;
}

ValueImpl::ValueImpl(const ValueImpl & other)
 : ref(other.ref), type(other.type), engine(other.engine)
{
  assert(type.isNull() || type == Type::Void);
}

ValueImpl::~ValueImpl()
{
  clear();
}

void ValueImpl::set_qobject(QObject *obj)
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
  {
    new (&data.builtin) BuiltIn;
    type = type.withFlag(Type::BuiltInStorageFlag);
  }
  
  data.builtin.qobject = obj;
}


bool ValueImpl::is_object() const
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
	return false;
  return !data.builtin.object.isNull();
}

const Object & ValueImpl::get_object() const
{
  return data.builtin.object;
}

void ValueImpl::init_object()
{
  if(type.testFlag(Type::BuiltInStorageFlag)) 
  {
    /// TODO : get QObject and prepare to add members
  }
  else
  {
    if (!data.builtin.object.isNull())
      return;
    
    auto impl = std::make_shared<ObjectImpl>(this->engine->getClass(this->type));
    data.builtin.object = Object{ impl };
  }
}

void ValueImpl::push_member(const Value & val)
{
  data.builtin.object.push(val);
}

Value ValueImpl::pop_member()
{
  return data.builtin.object.pop();
}

Value ValueImpl::get_member(size_t i) const
{
  return data.builtin.object.at(i);
}

size_t ValueImpl::member_count() const
{
  return data.builtin.object.size();
}


bool ValueImpl::is_array() const
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
	return false;
  return !data.builtin.array.isNull();
}

const Array & ValueImpl::get_array() const
{
  return data.builtin.array;
}

void ValueImpl::set_array(const Array & aval)
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
  {
    new (&data.builtin) BuiltIn;
    type = type.withFlag(Type::BuiltInStorageFlag);
  }
  
  data.builtin.array = aval;
}


bool ValueImpl::is_function() const
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
	return false;
  return !data.builtin.function.isNull();
}

const Function & ValueImpl::get_function() const
{
  return data.builtin.function;
}

void ValueImpl::set_function(const Function & fval)
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
  {
    new (&data.builtin) BuiltIn;
    type = type.withFlag(Type::BuiltInStorageFlag);
  }
  
  data.builtin.function = fval;
}

bool ValueImpl::is_lambda() const
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
	return false;
  return !data.builtin.lambda.isNull();
}

const Lambda & ValueImpl::get_lambda() const
{
  return data.builtin.lambda;
}

void ValueImpl::set_lambda(const Lambda & lval)
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
  {
    new (&data.builtin) BuiltIn;
    type = type.withFlag(Type::BuiltInStorageFlag);
  }
  
  data.builtin.lambda = lval;
}

const Enumerator & ValueImpl::get_enumerator() const
{
  return data.builtin.enumerator;
}

void ValueImpl::set_enumerator(const Enumerator & en)
{
  if(!type.testFlag(Type::BuiltInStorageFlag))
  {
    new (&data.builtin) BuiltIn;
    type = type.withFlag(Type::BuiltInStorageFlag);
  }
  
  data.builtin.enumerator = en;
}

bool ValueImpl::is_initializer_list() const
{
  if (!type.testFlag(Type::BuiltInStorageFlag))
    return false;

  return data.builtin.initializer_list.begin() != nullptr;
}

InitializerList ValueImpl::get_initializer_list() const
{
  return data.builtin.initializer_list;
}

void ValueImpl::set_initializer_list(const InitializerList & il)
{
  if (!type.testFlag(Type::BuiltInStorageFlag))
  {
    new (&data.builtin) BuiltIn;
    type = type.withFlag(Type::BuiltInStorageFlag);
  }

  data.builtin.initializer_list = il;
}


QObject* Value::toQObject() const
{
  return d->data.builtin.qobject;
}

void* Value::getPtr() const
{
  return d->data.ptr;
}

} // namespace script