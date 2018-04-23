#include "StrBlob.h"
#include "StrBlobPtr.h"

StrBlobPtr StrBlob::begin() 
{ 
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() 
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
