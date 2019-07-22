open Belt.Option;

/**
 The [Intl.DateTimeFormat](https://www.ecma-international.org/ecma-402/1.0/#sec-12) type.
 */
type t;

type day = Numeric | TwoDigit;
type era = Long | Short | Narrow;
type formatMatcher = Basic | BestFit;
type hour = Numeric | TwoDigit;
type hourCycle = H11 | H12 | H23 | H24;
type localeMatcher = Lookup | BestFit;
type minute = Numeric | TwoDigit;
type month = Numeric | TwoDigit | Long | Short | Narrow;
type second = Numeric | TwoDigit;
type timeZoneName = Long | Short;
type weekday = Long | Short | Narrow;
type year = Numeric | TwoDigit;

[@bs.deriving abstract]
type rawResolvedOptionsResp = {
    [@bs.optional] locale: string,
    [@bs.optional] calendar: string,
    [@bs.optional] numberingSystem: string,
    [@bs.optional] timeZone: Js.Nullable.t(string),
    [@bs.optional] hour12: bool,
    [@bs.optional] weekday: string,
    [@bs.optional] era: string,
    [@bs.optional] year: string,
    [@bs.optional] month: string,
    [@bs.optional] day: string,
    [@bs.optional] hour: string,
    [@bs.optional] minute: string,
    [@bs.optional] second: string,
    [@bs.optional] timeZoneName: string,
};

/**
 Direct port of [Intl.DateTimeFormat.prototype.resolvedOptions](https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3).

 This will not attempt to strongly type the output.  For nicer typed output, use the `resolvedOptions` method.
 */
[@bs.send] external rawResolvedOptions: t => rawResolvedOptionsResp = "resolvedOptions";

type resolvedOptionsResp = {
    locale: option(string),
    calendar: option(string),
    numberingSystem: option(string),
    timeZone: option(string),
    hour12: option(bool),
    weekday: option(weekday),
    era: option(era),
    year: option(year),
    month: option(month),
    day: option(day),
    hour: option(hour),
    minute: option(minute),
    second: option(second),
    timeZoneName: option(timeZoneName),
};

exception InvalidWeekday(string);
exception InvalidEra(string);
exception InvalidYear(string);
exception InvalidMonth(string);
exception InvalidDay(string);
exception InvalidHour(string);
exception InvalidMinute(string);
exception InvalidSecond(string);
exception InvalidTimeZoneName(string);

/**
 Port of [Intl.DateTimeFormat.prototype.resolvedOptions](https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.3).

 If a value that isn't described in the ECMA standard is encountered, this method will raise an exception.
 You can use the `rawResolvedOptions` method if you need to accomodate behavior outside of the spec.
 See [Table 3](https://www.ecma-international.org/ecma-402/1.0/#table-3) for a listing of what options the JS runtime can return.
 */
let resolvedOptions = self => {
    let rawResp = rawResolvedOptions(self);
    {
        locale: localeGet(rawResp),
        calendar: calendarGet(rawResp),
        numberingSystem: numberingSystemGet(rawResp),
        timeZone: Belt.Option.flatMap(timeZoneGet(rawResp), tz => Js.Nullable.toOption(tz)),
        hour12: hour12Get(rawResp),
        weekday: Belt.Option.map(weekdayGet(rawResp), (w): weekday => switch (w) {
        | "narrow" => Narrow
        | "short" => Short
        | "long" => Long
        | _ => raise(InvalidWeekday(w))
        }),
        era: Belt.Option.map(eraGet(rawResp), (e): era => switch (e) {
        | "narrow" => Narrow
        | "short" => Short
        | "long" => Long
        | _ => raise(InvalidEra(e))
        }),
        year: Belt.Option.map(yearGet(rawResp), (y): year => switch (y) {
        | "2-digit" => TwoDigit
        | "numeric" => Numeric
        | _ => raise(InvalidYear(y))
        }),
        month: Belt.Option.map(monthGet(rawResp), (m): month => switch (m) {
        | "2-digit" => TwoDigit
        | "numeric" => Numeric
        | "narrow" => Narrow
        | "short" => Short
        | "long" => Long
        | _ => raise(InvalidMonth(m))
        }),
        day: Belt.Option.map(dayGet(rawResp), (d): day => switch (d) {
        | "2-digit" => TwoDigit
        | "numeric" => Numeric
        | _ => raise(InvalidDay(d))
        }),
        hour: Belt.Option.map(hourGet(rawResp), (h): hour => switch (h) {
        | "2-digit" => TwoDigit
        | "numeric" => Numeric
        | _ => raise(InvalidHour(h))
        }),
        minute: Belt.Option.map(minuteGet(rawResp), (m): minute => switch (m) {
        | "2-digit" => TwoDigit
        | "numeric" => Numeric
        | _ => raise(InvalidMinute(m))
        }),
        second: Belt.Option.map(secondGet(rawResp), (s): second => switch (s) {
        | "2-digit" => TwoDigit
        | "numeric" => Numeric
        | _ => raise(InvalidSecond(s))
        }),
        timeZoneName: Belt.Option.map(timeZoneNameGet(rawResp), (tzn): timeZoneName => switch (tzn) {
        | "short" => Short
        | "long" => Long
        | _ => raise(InvalidTimeZoneName(tzn))
        }),
    }
};

/**
 Port of [Intl.DateTimeFormat.prototype.format](https://www.ecma-international.org/ecma-402/1.0/#sec-12.3.2).
 */
[@bs.send] external format: (t, Js.Date.t) => string = "format";

[@bs.deriving abstract]
type rawPart = {
    [@bs.as "type"] type_: string,
    value: string,
};

[@bs.send] external formatToParts_: (t, Js.Date.t) => array(rawPart) = "formatToParts";

type partType = Day | DayPeriod | Era | Hour | Literal | Minute | Month | Second | TimeZoneName | Weekday | Year;

type part = {
    type_: partType,
    value: string,
};

exception InvalidPart(rawPart);

/**
 Port of [Intl.DateTimeFormat.prototype.formatToParts](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat/formatToParts).
 */
let formatToParts = (self, date) => {
    Belt.Array.map(formatToParts_(self, date), rp => {
        let type_ = switch (type_Get(rp)) {
        | "day" => Day
        | "dayPeriod" => DayPeriod
        | "era" => Era
        | "hour" => Hour
        | "literal" => Literal
        | "minute" => Minute
        | "month" => Month
        | "second" => Second
        | "timeZoneName" => TimeZoneName
        | "weekday" => Weekday
        | "year" => Year
        | _ => raise(InvalidPart(rp))
        };
        {
            type_: type_,
            value: valueGet(rp),
        }
    })
};

[@bs.deriving abstract]
type supportedLocalesOfOptions = {
    [@bs.optional] mutable localeMatcher: string,
};

[@bs.scope "Intl.DateTimeFormat"] [@bs.val] external supportedLocalesOf_: (array(string), supportedLocalesOfOptions) => array(string) = "supportedLocalesOf";

/**
 Port of [Intl.DateTimeFormat.supportedLocalesOf](https://www.ecma-international.org/ecma-402/1.0/#sec-12.2.2).
 */
let supportedLocalesOf = (locales, ~localeMatcher=?, ()) => {
    let opts = supportedLocalesOfOptions(());
    if (isSome(localeMatcher)) {
        localeMatcherSet(opts, switch (getExn(localeMatcher)) {
        | Lookup => "lookup"
        | BestFit => "best fit"
        })
    }
    supportedLocalesOf_(locales, opts)
};

[@bs.deriving abstract]
type newDateTimeFormatOptions = {
    [@bs.optional] mutable day: string,
    [@bs.optional] mutable era: string,
    [@bs.optional] mutable formatMatcher: string,
    [@bs.optional] mutable hour: string,
    [@bs.optional] mutable hour12: bool,
    [@bs.optional] mutable hourCycle: string,
    [@bs.optional] mutable localeMatcher: string,
    [@bs.optional] mutable minute: string,
    [@bs.optional] mutable month: string,
    [@bs.optional] mutable second: string,
    [@bs.optional] mutable timeZone: string,
    [@bs.optional] mutable timeZoneName: string,
    [@bs.optional] mutable weekday: string,
    [@bs.optional] mutable year: string,
};

[@bs.new] [@bs.scope "Intl"] external newJSDateTimeFormat: (array(string), newDateTimeFormatOptions) => t = "DateTimeFormat";

/**
 Port of [new Intl.DateTimeFormat](https://www.ecma-international.org/ecma-402/1.0/#sec-12.1.3.1), but more OCaml-esque.
 */
let make = (~locales, ~day: option(day)=?, ~era: option(era)=?, ~formatMatcher=?, ~hour: option(hour)=?, ~hourCycle=?, ~localeMatcher=?, ~minute: option(minute)=?, ~month: option(month)=?, ~second: option(second)=?, ~timeZoneName: option(timeZoneName)=?, ~weekday: option(weekday)=?, ~year: option(year)=?, ()) => {
    let opts = newDateTimeFormatOptions(());
    if (isSome(day)) {
        daySet(opts, switch (getExn(day)) {
        | Numeric => "numeric"
        | TwoDigit => "2-digit"
        });
    };
    if (isSome(era)) {
        eraSet(opts, switch (getExn(era)) {
        | Long => "long"
        | Short => "short"
        | Narrow => "narrow"
        });
    };
    if (isSome(formatMatcher)) {
        formatMatcherSet(opts, switch (getExn(formatMatcher)) {
        | Basic => "basic"
        | BestFit => "best fit"
        });
    };
    if (isSome(hour)) {
        hourSet(opts, switch (getExn(hour)) {
        | Numeric => "numeric"
        | TwoDigit => "2-digit"
        });
    };
    if (isSome(hourCycle)) {
        hourCycleSet(opts, switch (getExn(hourCycle)) {
        | H11 => "h11"
        | H12 => "h12"
        | H23 => "h23"
        | H24 => "h24"
        });
    };
    if (isSome(localeMatcher)) {
        localeMatcherSet(opts, switch (getExn(localeMatcher)) {
        | Lookup => "lookup"
        | BestFit => "best fit"
        });
    };
    if (isSome(minute)) {
        minuteSet(opts, switch (getExn(minute)) {
        | Numeric => "numeric"
        | TwoDigit => "2-digit"
        });
    };
    if (isSome(month)) {
        monthSet(opts, switch (getExn(month)) {
        | Numeric => "numeric"
        | TwoDigit => "2-digit"
        | Long => "long"
        | Short => "short"
        | Narrow => "narrow"
        });
    };
    if (isSome(second)) {
        secondSet(opts, switch (getExn(second)) {
        | Numeric => "numeric"
        | TwoDigit => "2-digit"
        });
    };
    if (isSome(timeZoneName)) {
        timeZoneNameSet(opts, switch (getExn(timeZoneName)) {
        | Long => "long"
        | Short => "short"
        });
    };
    if (isSome(weekday)) {
        weekdaySet(opts, switch (getExn(weekday)) {
        | Long => "long"
        | Short => "short"
        | Narrow => "narrow"
        });
    };
    if (isSome(year)) {
        yearSet(opts, switch (getExn(year)) {
        | Numeric => "numeric"
        | TwoDigit => "2-digit"
        });
    };
    newJSDateTimeFormat(locales, opts)
};