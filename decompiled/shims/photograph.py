# Source Generated with Decompyle++
# File: photograph.pyc (Python 3.9)

import logging
from subprocess import check_output

def main():
    
    try:
        capture_shell = 'capture 0'
        logging.info(capture_shell)
        capture_ret = check_output(capture_shell, shell=True).decode('utf-8')
        logging.info('capture 0 return:#%s#' % str(capture_ret))
    except Exception:
        err = None
        
        try:
            logging.error(err)
        finally:
            err = None
            del err
        err = None
        del err
        return None



if __name__ == '__main__':
    main()
