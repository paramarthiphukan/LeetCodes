class TimeLimitedCache {
    keyValue: {
        [key: string]: {
            value: number;
            expiredTime: number;
        }
    }

    constructor() {
        this.keyValue = {};
    }

    set(key: number, value: number, duration: number): boolean {
        let isKeyExist = false;

        if(this.keyValue[key]) isKeyExist = true;

        this.keyValue[key] = {
            value,
            expiredTime: Date.now() + duration
        }

        return isKeyExist;
    }

    get(key: number): number {
        if(!this.keyValue[key]) return -1;
        
        if(Date.now() > this.keyValue[key].expiredTime) return -1;

        return this.keyValue[key].value;
    }

	count(): number {
        let currentTime = Date.now();

        return Object.values(this.keyValue).reduce((acc, curr) => {
            if(currentTime < curr.expiredTime) acc += 1;

            return acc;
        }, 0)
    }
}


/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */