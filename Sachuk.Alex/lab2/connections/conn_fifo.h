#pragma once

#include "abstr_conn.h"

class FifoConnection : public AbstractConnection {
private:
    bool isHost;
    std::string fifoFilename;
    int fileId;

public:
    FifoConnection(pid_t pid, bool isHost) : isHost(isHost) {this->fifoFilename = "/tmp/fifo_" + std::to_string(pid);};

    void connOpen(size_t id, bool create) override;
    void connRead(void* buf, size_t count) override;
    void connWrite(void* buf, size_t count) override;
    void connClose() override;
    
    ~FifoConnection() = default;
};