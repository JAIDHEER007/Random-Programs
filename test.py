from csv import excel


class Toy:
    def __init__(self, tid, ttype, price) -> None:
        self.tid = tid
        self.ttype = ttype
        self.price = price
        self.discountApplicable = 0


class Store:
    def __init__(self, toyObjs, toyDetails) -> None:
        self.toyObjs = toyObjs
        self.toyDetails = toyDetails

    def calculateDiscount(self):
        for i in range(len(self.toyObjs)):
            try:
                rate = self.toyDetails[self.toyObjs[i].ttype]
                price = self.toyObjs[i].price
                self.toyObjs[i].discountApplicable = price * (rate / 100)
            except Exception:
                 self.toyObjs[i].discountApplicable = 0

if __name__ == '__main__':
    n = int(input())

    toysLst = []
    for _ in range(n):
        tid = int(input())
        ttype = input()
        price = int(input())

        toy = Toy(tid, ttype, price)

        toysLst.append(toy)

    toyDetails = {}
    for _ in range(3):
        ttype = input()
        rate = int(input())

        toyDetails[ttype] = rate

    store1 = Store(toysLst, toyDetails); 
    store1.calculateDiscount()
    
    # Output
    for toy in store1.toyObjs:
        tid = toy.tid
        price = toy.price
        discountPrice = price - toy.discountApplicable

        print("{} {} {}".format(tid, price, discountPrice))



