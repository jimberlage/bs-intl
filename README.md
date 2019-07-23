# bs-intl

[![NPM](https://nodei.co/npm/bs-intl.png?compact=true)](https://nodei.co/npm/bs-intl/)
[![CircleCI](https://circleci.com/gh/jimberlage/bs-intl.svg?style=svg)](https://circleci.com/gh/jimberlage/bs-intl)

A port of the [Intl](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl) utilities of JS to Reason.

## Installation

```bash
yarn add bs-intl
```

## Status

The following pieces of the API are completed:

### Intl.Collator

- [ ] [Constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Collator)
- [ ] [supportedLocalesOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Collator/supportedLocalesOf)
- [ ] [compare](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Collator/compare)
- [ ] [resolvedOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Collator/resolvedOptions)

### Intl.DateTimeFormat

- [x] [Constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat)
- [x] [supportedLocalesOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat/supportedLocalesOf)
- [x] [format](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat/format)
- [x] [formatToParts](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat/formatToParts)
- [x] [resolvedOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DateTimeFormat/resolvedOptions)

### Intl.ListFormat

- [ ] [Constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ListFormat)
- [ ] [supportedLocalesOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ListFormat/supportedLocalesOf)
- [ ] [format](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ListFormat/format)
- [ ] [formatToParts](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ListFormat/formatToParts)
- [ ] [resolvedOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ListFormat/resolvedOptions)

### Intl.NumberFormat

- [ ] [Constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat)
- [ ] [supportedLocalesOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat/supportedLocalesOf)
- [ ] [format](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat/format)
- [ ] [formatToParts](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat/formatToParts)
- [ ] [resolvedOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NumberFormat/resolvedOptions)

### Intl.PluralRules

- [ ] [Constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules)
- [ ] [supportedLocalesOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules/supportedLocalesOf)
- [ ] [select](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules/select)
- [ ] [resolvedOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/PluralRules/resolvedOptions)

### Intl.RelativeTimeFormat

- [ ] [Constructor](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RelativeTimeFormat)
- [ ] [supportedLocalesOf](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RelativeTimeFormat/supportedLocalesOf)
- [ ] [format](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RelativeTimeFormat/format)
- [ ] [formatToParts](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RelativeTimeFormat/formatToParts)
- [ ] [resolvedOptions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RelativeTimeFormat/resolvedOptions)