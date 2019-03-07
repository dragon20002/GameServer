#pragma once
#include "stdafx.h"
#include "PacketHeader.h"
#include "Stream.h"

class Packet {
public:
    virtual PacketType type() = 0;
    virtual void encode(Stream &stream) { stream << (Int64) this->type(); };
    virtual void decode(Stream &stream) {};
};

class PK_C_REQ_EXIT : public Packet
{
public:
    PacketType type() { return E_C_REQ_EXIT; }
};

class PK_S_ANS_EXIT : public Packet
{
public:
    PacketType type() { return E_S_ANS_EXIT; }
};

class PK_I_NOTIFY_TERMINAL : public Packet
{
public:
    PacketType type() { return E_I_NOTIFY_TERMINAL; }
};

class PK_C_REQ_HEARTBEAT : public Packet
{
public:
    PacketType type() { return E_C_REQ_HEARTBEAT; }
};

class PK_S_ANS_HEARTBEAT : public Packet
{
public:
    PacketType type() { return E_S_ANS_HEARTBEAT; }
};

class PK_C_REQ_ID_PW : public Packet
{
public:
    PacketType type() { return E_C_REQ_ID_PW; }
    std::string     id_;
    std::string     password_;

    void encode(Stream &stream) {
        stream << (Int64) this->type();
        stream << id_;
        stream << password_;
    }

    void decode(Stream &stream) {
        stream >> &id_;
        stream >> &password_;
    }
};

class PK_S_ANS_ID_PW : public Packet
{
public:
    PacketType type() { return E_S_ANS_ID_PW; }
    Byte     result_;

    void encode(Stream &stream) {
        stream << (Int64) this->type();
        stream << result_;
    }

    void decode(Stream &stream) {
        stream >> &result_;
    }
};

class PK_I_DB_REQ_ID_PW : public Packet
{
public:
    PacketType type() { return E_I_DB_REQ_ID_PW; }
    UInt64     clientId_;
    std::string     id_;
    std::string     password_;

    void encode(Stream &stream) {
        stream << (Int64) this->type();
        stream << clientId_;
        stream << id_;
        stream << password_;
    }

    void decode(Stream &stream) {
        stream >> &clientId_;
        stream >> &id_;
        stream >> &password_;
    }
};

class PK_I_DB_ANS_ID_PW : public Packet
{
public:
    PacketType type() { return E_I_DB_ANS_ID_PW; }
    UInt64     clientId_;
    std::string     id_;
    Byte     result_;

    void encode(Stream &stream) {
        stream << (Int64) this->type();
        stream << clientId_;
        stream << id_;
        stream << result_;
    }

    void decode(Stream &stream) {
        stream >> &clientId_;
        stream >> &id_;
        stream >> &result_;
    }
};

class PK_C_REQ_CHATTING : public Packet
{
public:
    PacketType type() { return E_C_REQ_CHATTING; }
    std::string     text_;

    void encode(Stream &stream) {
        stream << (Int64) this->type();
        stream << text_;
    }

    void decode(Stream &stream) {
        stream >> &text_;
    }
};

class PK_S_ANS_CHATTING : public Packet
{
public:
    PacketType type() { return E_S_ANS_CHATTING; }
    std::string     id_;
    std::string     text_;

    void encode(Stream &stream) {
        stream << (Int64) this->type();
        stream << id_;
        stream << text_;
    }

    void decode(Stream &stream) {
        stream >> &id_;
        stream >> &text_;
    }
};


