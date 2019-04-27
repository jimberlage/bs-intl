open Belt.Option;

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

type t;

[@bs.send] external format: (t, Js.Date.t) => string = "format";

[@bs.new] [@bs.scope "Intl"] external newJSDateTimeFormat: (array(string), newDateTimeFormatOptions) => t = "DateTimeFormat";

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