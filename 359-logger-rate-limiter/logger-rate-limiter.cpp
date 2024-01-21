class Logger {
public:

    unordered_map<string, int> log;
    // int cnt = 0;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(log.find(message) == log.end()){
            log[message] = timestamp;
            return true;
        }
        else{
            if(timestamp >= log[message] + 10){
                log[message] = timestamp;
                return true;
            }
            else{
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */