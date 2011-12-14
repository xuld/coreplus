#ifndef COREPLUS_THROWER_H
#define COREPLUS_THROWER_H


#ifdef SYSTEM_THROW

#define THROW_IF(condition, Exception, msg) if(condition) throw new Exception(msg);
#define THROW_IF1(condition, Exception, msg, args) if(condition) throw new Exception(msg, args);
#define THROW_IF_LENGTH(index, length, maxLength) if(length < 0)throw new ArgumentOutOfRange("length");else if(index < 0 || index + length >= maxLength) throw new ArgumentOutOfRange("index");

#else

#define THROW_IF(condition, Exception, msg)
#define THROW_IF1(condition, Exception, msg, args)
#define THROW_IF_LENGTH(index, length, maxLength)



#endif

#endif