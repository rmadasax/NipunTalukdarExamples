/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "remotecommand_types.h"

namespace RemoteCommand {

int _kOperationValues[] = {
  Operation::EXECUTEBIN,
  Operation::EXECUTESCRIPT
};
const char* _kOperationNames[] = {
  "EXECUTEBIN",
  "EXECUTESCRIPT"
};
const std::map<int, const char*> _Operation_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kOperationValues, _kOperationNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* BadOperation::ascii_fingerprint = "96705E9A3FD7B072319C71653E0DBB90";
const uint8_t BadOperation::binary_fingerprint[16] = {0x96,0x70,0x5E,0x9A,0x3F,0xD7,0xB0,0x72,0x31,0x9C,0x71,0x65,0x3E,0x0D,0xBB,0x90};

uint32_t BadOperation::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->what);
          this->__isset.what = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t BadOperation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("BadOperation");
  xfer += oprot->writeFieldBegin("what", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->what);
  xfer += oprot->writeFieldEnd();
  if (this->__isset.reason) {
    xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->reason);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* Command::ascii_fingerprint = "6B417694B733691D9995A4D7E02384BB";
const uint8_t Command::binary_fingerprint[16] = {0x6B,0x41,0x76,0x94,0xB7,0x33,0x69,0x1D,0x99,0x95,0xA4,0xD7,0xE0,0x23,0x84,0xBB};

uint32_t Command::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->op = (Operation::type)ecast0;
          this->__isset.op = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->commandFile);
          this->__isset.commandFile = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isBinary);
          this->__isset.isBinary = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->parameters.clear();
            uint32_t _size1;
            ::apache::thrift::protocol::TType _etype4;
            iprot->readListBegin(_etype4, _size1);
            this->parameters.resize(_size1);
            uint32_t _i5;
            for (_i5 = 0; _i5 < _size1; ++_i5)
            {
              xfer += iprot->readString(this->parameters[_i5]);
            }
            iprot->readListEnd();
          }
          this->__isset.parameters = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->stdErrorFile);
          this->__isset.stdErrorFile = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->stdOutFile);
          this->__isset.stdOutFile = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->daemonize);
          this->__isset.daemonize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Command::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Command");
  xfer += oprot->writeFieldBegin("op", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->op);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("commandFile", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->commandFile);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("isBinary", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->isBinary);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("parameters", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->parameters.size()));
    std::vector<std::string> ::const_iterator _iter6;
    for (_iter6 = this->parameters.begin(); _iter6 != this->parameters.end(); ++_iter6)
    {
      xfer += oprot->writeString((*_iter6));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("stdErrorFile", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->stdErrorFile);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("stdOutFile", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->stdOutFile);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("daemonize", ::apache::thrift::protocol::T_BOOL, 7);
  xfer += oprot->writeBool(this->daemonize);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

} // namespace
