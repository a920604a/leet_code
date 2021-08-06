import threading, time
class Singleton:
    __instance = None
    def __init__(self):
        time.sleep(1)
        if not Singleton.__instance:
            print(" __init__ method called")
        else:
            print(f"Instance already created: {self.getInstance()}")
    
    @classmethod
    def getInstance(cls):
        if not cls.__instance:
            cls.__instance = Singleton()
        return cls.__instance
        
        
def Singleton(cls):
    _instance = {}

    def _singleton(*args, **kargs):
        if cls not in _instance:
            _instance[cls] = cls(*args, **kargs)
        return _instance[cls]

    return _singleton

@Singleton
class A(object):
    a = 1
    __instance = None
    _instance_lock = threading.Lock()
    
    def __new__(cls,):
        if not hasattr(A, "_instance"):
            with A._instance_lock:
                if not hasattr(A, "_instance"):
                    A._instance = object.__new__(cls)  
        return A._instance
        
        return cls.__instance

    def __init__(self, x=0):
        time.sleep(0.1)
        self.x = x
       
        




def task(arg):
    obj = A()
    print(obj)

for i in range(2):
    t = threading.Thread(target=task,args=[i,])
    t.start()