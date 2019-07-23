(** Bindings to the Intl object, containing internationalization functions for Javascript.

 Note that nodejs does **not** come with the necessary internationalization files by default.  If this library isn't working for you in a nodejs context, that's likely the reason.  You'll need to roll your own node, or use something like https://github.com/unicode-org/full-icu-npm
 *)

(** Handles functions related to the [Intl.DateTimeFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat) object.
 *)
module DateTimeFormat = Intl_DateTimeFormat

(** Handles functions related to the [Intl.NumberFormat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat) object.
 *)
module NumberFormat = Intl_NumberFormat