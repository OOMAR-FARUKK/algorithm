#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5;

vector<ll>v(N, 0);
ll lis(ll n) {
    vector<ll>lis_arr;
    lis_arr.push_back(v[0]);
    for (int i = 1; i < n; i++) {

        if (v[i] > lis_arr[lis_arr.size() - 1]) {
            lis_arr.push_back(v[i]);

        }
        else {

            auto it = lower_bound(lis_arr.begin(), lis_arr.end(), v[i]);
            int index = (it - lis_arr.begin());
            lis_arr[index] = v[i];
        }
    }

    return lis_arr.size();
}
void solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout<<lis(n);


}
int main() {

    solve();
    return 0;

}







/*
যদি একটি সিকুয়েন্স দেয়া থাকে নাম্বারের এবং এই সিকুয়েন্স থেকে যদি বলা হয় দীর্ঘতম ক্রমবর্ধমান বা ক্রমহ্রাসমান সংখ্যার lenth করতে তাহলে ডাইনামিক প্রোগ্রামিং এর ব্যাবহার করা লাগবে এবং তখন টাইম কমপ্লেক্সিটি হবে (n^2). এর থেকে তাড়াতাড়ি কেমনে করা যায় নিচে সেটাই দেখবো-

প্রথমে n সংখ্যাক সংখ্যা ইনপুট নিয়ে একটি অ্যারেতে রাখতে হবে।longest increasing  subsequence রাখার জন্য একটি ভেক্টর lis_arr ডিক্লেয়ার করে রাখালাম।যেহেতু প্রত্যেক সংখ্যাই তার একটি সাবসিকুয়েন্স,তাই সাবসিকুয়েন্স এর লেন্থ ০ হতে পারবে না,এইজন্য lis_arr তে প্রথমেই ভেক্টরের প্রথম সংখ্যাটা রেখে দিতে হবে।একটি for লুপ নিয়ে ১--n পর্যন্ত চালাতে হবে।
এখন দুইটা কন্ডিশন, যদি ভেক্টরের কারেন্ট ইলিমেন্ট lis_arr এর top ইলিমেন্ট থেকে বড় হয় তাহলে সোজা তা lis_arr তে পুশ হবে।,আর যদি  যদি ভেক্টরের কারেন্ট ইলিমেন্ট lis_arr এর top ইলিমেন্ট থেকে ছোট হয়, তাহলে আমরা lis_arr তে ভেক্টরের কারেন্ট ইলিমেন্ট এর সমান বা বড় সংখ্যা খুজবো এবং lis_arr এর ঐ ইলিমেন্ট কে ভেক্টরের কারেন্ট ইলিমেন্ট দিয়ে রিপ্লেস করবো।ধরলাম আমাদের সংখ্যা আছে ১ ২  ৪ ৫ ৬ ৮ ৩
এখন ধরলাম আমাদের ভেক্টর এর কারেন্ট ইলিমেন্ট আছে ইনডেক্স ৬ এ মানে সংখ্যা ৩ এ।তাহলে উপরের কন্ডিশন অনুযায়ী ৪ কে আমরা ৩ দিয়ে রিপ্লেস করবো,বাট এটার তো কোনো দরকার নেই কারন ৪ কে ৩ দিয়ে। রিপ্লেস করলে lis_arr সাইজের। কোনো পরিবর্তন হবে না। আসলে এই উদাহরনে সমস্যা না হলেও আরেকটি উদাহরণ দেখা যাক।
ধরি আমাদের আরেকটি আ্যরে ১ ৫  ২ ৩ ৪
এখন ধরা যাক আমাদের ভেক্টরের কারেন্ট ইলিমেন্ট ২ এ আছে, তাহলে lis_arr  তে ইলিমেন্ট আছে (১  ৫)
এখন ২ এর জন্য যদি আমরা ৫ রিপ্লেস না করি তাহলে আমরা ২ ৩ ৪ পুশ করতে পারবো না  এবং আল্টিমেটলি  lis_arr এর সাইজ হবে ২। বাট দেখাই৷ যাচ্ছে আমাদের longest subsequence এর লেন্থ ৪। তাই ২ ৩ ৪ কে পুশ করার জন্য আমাদের ৫ কে রিপ্লেস করা লাগবে।
এইখানে একটাই সমস্যা আমরা সব সময় increasing subsequence এর length পাবো, সাবসিকুয়েন্স কখনো পাবো না।
এই এলগরিদম এর টাইম কমপ্লেক্সিটি nlog(n).
*/