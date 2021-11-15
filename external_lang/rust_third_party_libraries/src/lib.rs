//#![no_std]

#[no_mangle]
pub extern "C" fn zoo(input:u8) -> u8 {
 input
}

// pointers ------------------------------------------------------
use counter::{Counter,Args};
pub mod counter {
// `#[repr(C)]` or `#[repr(transparent)]` 
    #[repr(C)]
    pub struct Args {
        init: u32,
        by: u32,
    }
    impl Args {
        pub fn new(init: u32,by: u32) -> Args {
            Args{init: init, by: by}
        }
    }
    pub struct Counter {
        val: u32
    }

    impl Counter {
        pub fn new(val: u32) -> Counter {
            Counter{val: val}
        }

        pub fn new_args(args: Args) -> Counter {
            Counter{
                val: args.init + args.by
            }
        }

        pub fn get(&self) -> u32 {
            self.val
        }

        pub fn incr(&mut self, by: u32) -> u32 {
            self.val += by;
            self.val
        }

        pub fn decr(&mut self, by: u32) -> u32 {
            self.val -= by;
            self.val
        }

        pub fn incr_array(&mut self, bys: &[u32]) -> u32 {
            for by in bys {
                self.val += *by;
            }
            self.val
        }

        pub fn decr_array(&mut self, bys: &[u32]) -> u32 {
            for by in bys {
                self.val -= *by;
            }
            self.val
        }

    }
}

use std::mem::transmute;

#[no_mangle]
pub extern fn createCounter(val: u32) -> *mut Counter {
    let _counter = unsafe { transmute(Box::new(Counter::new(val))) };
    _counter
}
/*
    // альтернативный вариант
    #![feature(box_raw, box_syntax)]
    use std::boxed;
    pub extern "C" fn createCounter(val: u32) -> *mut Counter {
        boxed::into_raw(box Counter::new(val))
    }
*/
#[no_mangle]
pub extern fn createCounterArgs(args: Args) -> *mut Counter {
    let _counter = unsafe { transmute(Box::new(Counter::new_args(args))) };
    _counter
}

#[no_mangle]
pub extern fn getCounterValue(ptr: *mut Counter) -> u32 {
    let mut _counter = unsafe { &mut *ptr };
    _counter.get()
}

#[no_mangle]
pub extern fn incrementCounterBy(ptr: *mut Counter, by: u32) -> u32 {
    let mut _counter = unsafe { &mut *ptr };
    _counter.incr(by)
}

#[no_mangle]
pub extern fn decrementCounterBy(ptr: *mut Counter, by: u32) -> u32 {
    let mut _counter = unsafe { &mut *ptr };
    _counter.decr(by)
}

#[no_mangle]
pub extern fn incrementCounterArrayBy(ptr: *mut Counter, bys_ptr: *const u32, bys_len: usize) -> u32 {
    let mut _counter = unsafe { &mut *ptr };
    let bys = unsafe { std::slice::from_raw_parts(bys_ptr, bys_len) };
    _counter.incr_array(bys)
}

#[no_mangle]
pub extern fn decrementCounterArrayBy(ptr: *mut Counter, bys_ptr: *const u32, bys_len: usize) -> u32 {
    let mut _counter = unsafe { &mut *ptr };
    let bys = unsafe { std::slice::from_raw_parts(bys_ptr, bys_len) };
    _counter.decr_array(bys)
}

#[no_mangle]
pub extern fn destroyCounter(ptr: *mut Counter) {
    let _counter: Box<Counter> = unsafe{ transmute(ptr) };
    // Drop
}
/*
    // альтернативный вариант
    #[no_mangle]
    pub extern "C" fn destroyCounter(ptr: *mut RustStruct) {
        boxed::from_raw(ptr);
    }
*/

