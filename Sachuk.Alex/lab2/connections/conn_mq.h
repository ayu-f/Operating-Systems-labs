#pragma once

#include <mqueue.h>
#include "abstr_conn.h"

class MQConnection : public AbstractConnection {
private:
    const int MAX_SIZE = 4096;

    bool isCreator;
    std::string mqFilename;
    mqd_t mq;

public:
    MQConnection(pid_t pid, bool isHost) : isCreator(isHost) {this->mqFilename = "/tmp/mq_" + std::to_string(pid);};

    void connOpen(size_t id, bool create) override;
    void connRead(void* buf, size_t count) override;
    void connWrite(void* buf, size_t count) override;
    void connClose() override;

    ~MQConnection() = default;
};