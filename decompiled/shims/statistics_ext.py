# Source Generated with Decompyle++
# File: statistics_ext.pyc (Python 3.9)

import os
import time
import logging

class PrinterSysStats:
    
    def __init__(self, config):
        printer = config.get_printer()
        self.last_process_time = self.total_process_time = 0
        self.last_load_avg = 0
        self.last_mem_avail = 0
        self.mem_file = None
        
        try:
            self.mem_file = open('/proc/meminfo', 'r')
        finally:
            pass
        printer.register_event_handler('klippy:disconnect', self._disconnect)
        return None


    
    def _disconnect(self):
        if self.mem_file is not None:
            self.mem_file.close()
            self.mem_file = None

    
    def stats(self, eventtime):
        ptime = time.process_time()
        pdiff = ptime - self.last_process_time
        self.last_process_time = ptime
        if pdiff > 0:
            self.total_process_time += pdiff
        self.last_load_avg = os.getloadavg()[0]
        msg = 'sysload=%.2f cputime=%.3f' % (self.last_load_avg, self.total_process_time)
        if self.mem_file is not None:
            
            try:
                self.mem_file.seek(0)
                data = self.mem_file.read()
                for line in data.split('\n'):
                    if line.startswith('MemAvailable:'):
                        self.last_mem_avail = int(line.split()[1])
                        msg = '%s memavail=%d' % (msg, self.last_mem_avail)
                        self
                    
            return (False, msg)


    
    def get_status(self, eventtime):
        return {
            'sysload': self.last_load_avg,
            'cputime': self.total_process_time,
            'memavail': self.last_mem_avail,
            'monotonic': eventtime }



class PrinterStats:
    
    def __init__(self, config):
        self.printer = config.get_printer()
        reactor = self.printer.get_reactor()
        self.stats_timer = reactor.register_timer(self.generate_stats)
        self.stats_cb = []
        self.printer.register_event_handler('klippy:ready', self.handle_ready)

    
    def handle_ready(self):
        self.stats_cb = (lambda .0: [ o.stats for n, o in .0 if hasattr(o, 'stats') ])(self.printer.lookup_objects())
        if self.printer.get_start_args().get('debugoutput') is None:
            reactor = self.printer.get_reactor()
            reactor.update_timer(self.stats_timer, reactor.NOW)

    
    def generate_stats(self, eventtime):
        stats = [ cb(eventtime) for cb in (self.stats_cb) ]
        if max((lambda .0: [ s[0] for s in .0 ])(stats)):
            logging.info('Stats %.1f: %s', eventtime, ' '.join((lambda .0: [ s[1] for s in .0 ])(stats)))
        return eventtime + 3



def load_config(config):
    config.get_printer().add_object('system_stats', PrinterSysStats(config))
    return PrinterStats(config)

