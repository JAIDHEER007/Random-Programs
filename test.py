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
    olWithDiscount = []
    olWithoutDiscount = []

    for toy in store1.toyObjs:
        tid = toy.tid
        price = toy.price

        if toy.discountApplicable == 0:
            olWithoutDiscount.append([tid, price, price])
        else:
            olWithDiscount.append([tid, price, price - toy.discountApplicable])


    olWithDiscount.sort(key = lambda l:l[2], reverse = True)
    # olWithoutDiscount.sort(key = lambda l:l[2], reverse = True)

    for toy in olWithDiscount:
        print("{} {} {}".format(toy[0], toy[1], toy[2]))
    for toy in olWithoutDiscount:
        print("{} {} {}".format(toy[0], toy[1], toy[2]))



